
import sqlite3
from flask import Flask, render_template, request, flash,redirect,url_for,abort

app = Flask(__name__)

app.config["SECRET_KEY"] = "mykey"

def get_db_connection():
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

        if username1 == "":
            flash('Username is required!')
        elif password == "":
            flash('Password is required!')
        elif content == "":
            flash('Signature is required!')
        else:
           
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

    conn = get_db_connection()
    query = "Select * FROM users WHERE user='{}' AND pass='{}'".format(username,password)
    try:
        data = conn.execute(query)
        if "sqlite3.Cursor" in str(type(data)):
            data1 = []
            count = 1
            for i in data : 
                for count in range(4) :
                    data1.append(str(i[count]))

            data = data1
            correct = 1
    except Exception as err:
        errr = 1
        data = err

    conn.close()
    if data is None:
        abort(404)

    return render_template('profile.html',data=data,errr=errr,correct=correct)

    
if __name__ == "__main__" :
    app.run()


