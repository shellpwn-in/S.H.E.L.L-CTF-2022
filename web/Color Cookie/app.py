from flask import Flask,render_template,request, url_for

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('base.html')

@app.route('/check')
def cookie_check():
    color = request.args.get("C0loR")
    if (color == "blue" or color=="Blue") and (len(color) == 4):
        return render_template('Here_1s_flag.html')
    return render_template('base.html')

if __name__ == "__main__":
    app.run()
