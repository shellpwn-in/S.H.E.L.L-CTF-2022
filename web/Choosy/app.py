from urllib.parse import uses_relative
from flask import Flask,render_template,request, url_for

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')


@app.route('/result')
def result():
    
    user_input = request.args.get("input")
    user_input_temp = user_input.lower()
    user_input_temp = user_input_temp.replace("script","")
    if (("img" in user_input_temp) and ("alert" in user_input_temp or "onerror" in user_input_temp) and ("<" in user_input_temp) and (">" in user_input_temp)):
        
        user_input_temp =  '<img src =q onerror=prompt("shellctf{50oom3_P4yL0aDS_aM0ng_Maaa4nnY}")>'
    return render_template('results.html',user_input=user_input,user_input_temp=user_input_temp)

if __name__ == "__main__":
    app.run(debug=False)
