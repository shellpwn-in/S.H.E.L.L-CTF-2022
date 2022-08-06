
from flask import Flask,request,url_for,render_template
import os
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/wH4t_Y0u_d1d')
def checker():
    user_input = request.args.get("Th1nK_Tw1c3")
    li = ['c','d','l','s','f','l','a','g','.','t','x',';',' ','-','_','u','p','r','e','n','t','i','z','h','/']
   
    for i in user_input.lower():
        if i not in li:
            user_input = ''
    if "du" in user_input:
        user_input = user_input.replace("du","")
    if "ls" in user_input:
        user_input = user_input.replace("ls","")        
    if "cd" in user_input:
        user_input = user_input.replace("cd","")
    if "d .." in user_input:
        user_input = user_input.replace("d ..","d ")
    if "app.py" or "requirements.txt" or "static" or "templates" or "Dockerfile" in user_input:
        user_input = ""
    if "../" in user_input:
        user_input = ""

    try :
        proc = subprocess.Popen(user_input, stdout=subprocess.PIPE, shell=True) 
        (out, err) = proc.communicate() 
        store = out
        if len(store) != 0 :
            return render_template('index.html',store=store,user_input=user_input)
        else:
            return render_template('index.html')
    except:
        return render_template('index.html',user_input=user_input)

if __name__ == "__main__" :
    app.run()

