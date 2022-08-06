from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/', methods=['POST'])
def upload_file():
    uploaded_file = request.files['file']
    fname = uploaded_file.filename
    subs = fname.split(".",1)[1]
    if("pdf" not in subs and len(subs)==4 and "fdp" in subs):
        data = "shellctf{R1ghtt_t0_l3ft_0veRiDe_1s_k3Y}"
        return render_template('index.html',data=data)
    elif("pdf" in subs):
        data = "Yummmmmmmmmmyyyyy"
        return render_template('index.html',data=data)
    else:
        data = "Not Tasty"
        return render_template('index.html',data=data)

if __name__ == "__main__" :
    app.run()

