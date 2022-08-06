
from flask import Flask,request,url_for,render_template
import os
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/wH4t_Y0u_d1d')
def checker():
    user_input = request.args.get("inn")
    li = ['c','d','l','s','f','l','a','g','.','t','x',';',' ']
   
    for i in user_input.lower():
        if i not in li:
            user_input = ''
    
    if "ls" in user_input:
        user_input = user_input.replace("ls","")        
    if "cd" in user_input:
        user_input = user_input.replace("cd","")
    if "d .." in user_input:
        user_input = user_input.replace("d ..","d ")
    if "app.py" or "static" or "templates" or "requirements.txt" in user_input:
        user_input = ""
    
    try :
        proc = subprocess.Popen(user_input, stdout=subprocess.PIPE, shell=True) 
        (out, err) = proc.communicate() 
        store = out
        if len(store) != 0 :
            return render_template('index.html',store=store,user_input=user_input)
        else:
            return render_template('index.html',user_input=user_input)
    except:
        return render_template('index.html')

if __name__ == "__main__" :
    app.run()

