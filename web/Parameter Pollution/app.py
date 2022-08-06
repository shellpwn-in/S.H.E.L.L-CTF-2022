from datetime import datetime
from flask import Flask,render_template,request, url_for, make_response
import flask

app = Flask(__name__)

@app.route('/')
def index():
    try:
        header = flask.request.headers
        agent = header["User-Agent"]
        timer = header["Date"]
        t = int(timer[17:19])
        now = datetime.now().time() # time object
        current_time = now.strftime("%H:%M:%S")
        if agent == "Vinod" :
            res = make_response(render_template("Time.html",current_time=current_time))
            res.set_cookie('77686f616d5f695f616d', '55736572')
            try:
                now = datetime.now().time() # time object
                current_time = now.strftime("%H:%M:%S")
                h = int((str(now))[0:2])
                if  h - t > 2 :
            
                    verify = request.cookies.get("77686f616d5f695f616d") # whoam_i_am
                   
                    if verify == "41646d696e":                         # Admin
                        return render_template('S3cRe777.html')
                    else:
                        return render_template('S3cRe7.html')
                else:
                    return render_template('Time.html',current_time=current_time)
            except:
                return render_template('Time.html',current_time=current_time)
        else:
            res = make_response(render_template("base.html"))
            res.set_cookie('77686f616d5f695f616d', '55736572')
            return res
    except:
        now = datetime.now().time() # time object
        current_time = now.strftime("%H:%M:%S")
        if agent == "Vinod":
            return render_template('Time.html',current_time=current_time)
        else:
            res = make_response(render_template("base.html"))
            res.set_cookie('77686f616d5f695f616d', '55736572')
            return res



if __name__ == "__main__":
    app.run()
