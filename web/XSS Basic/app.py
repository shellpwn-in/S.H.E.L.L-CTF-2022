from urllib.parse import uses_relative
from flask import Flask,render_template,request, url_for

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('XSS.html')


@app.route('/result')
def result():
    
    user_input = request.args.get("input")
    user_input_temp = user_input.lower()
    user_input_temp = user_input_temp.replace("script","")
    if (("img" in user_input_temp) and ("alert" in user_input_temp or "onerror" in user_input_temp) and ("<" in user_input_temp) and (">" in user_input_temp)):
        
        user_input_temp =  '<img src =q onerror=prompt("shellctf{50m3_P4yL0aD5_4m0ng_M4nY}")>'
    
    return render_template('results.html',user_input=user_input,user_input_temp=user_input_temp)

if __name__ == "__main__":
    app.run(debug=True)

#<img src =q onerror=prompt(8)>