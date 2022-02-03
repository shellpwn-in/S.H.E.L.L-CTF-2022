FROM python:3.6-slim-buster
WORKDIR /app
COPY ../fake_flag/ app/flag=/flag/flag/flag/
COPY ../fake_flag/ app/flag==/flag/flag/flag/
COPY ../fake_flag/ app/flag===/flag/flag/flag/
COPY ../fake_flag/ app/flag====/flag/flag/flag/
COPY ../fake_flag/ app/flag=====/flag/flag/flag/
COPY ../fake_flag/ app/flag======/flag/flag/flag/
COPY ../fake_flag/ app/flag=======/flag/flag/flag/
COPY ../fake_flag/ app/flag========/flag/flag/flag/
COPY ../fake_flag/ app/flag=========/flag/flag/flag/
COPY ../fake_flag/ app/flag==========/flag/flag/flag/
COPY ../fake_flag/ app/flag===========/flag/flag/flag/
COPY ../fake_flag/ app/flag============/flag/flag/flag/
COPY ../fake_flag/ app/flag=============/flag/flag/flag/
COPY ../fake_flag/ app/flag==============/flag/flag/flag/
COPY ../fake_flag/ app/flag===============/flag/flag/flag/
COPY ../fake_flag/ app/flag================/flag/flag/flag/
COPY ../fake_flag/ app/flag=================/flag/flag/flag/
COPY ../fake_flag/ app/flag==================/flag/flag/flag/
COPY ../fake_flag/ app/flag===================/flag/flag/flag/
COPY ../fake_flag/ app/flag====================/flag/flag/flag/
COPY ../fake_flag/ app/flag=====================/flag/flag/flag/
COPY ../fake_flag/ app/flag======================/flag/flag/flag/
COPY ../fake_flag/ app/flag=======================/flag/flag/flag/
COPY ../fake_flag/ app/flag========================/flag/flag/flag/
COPY ../fake_flag/ app/flag=========================/flag/flag/flag/
COPY ../fake_flag/ app/flag==========================/flag/flag/flag/
COPY ../fake_flag/ app/flag===========================/flag/flag/flag/
COPY ../fake_flag/ app/flag/flag/flag/flag/
COPY ../fake_flag/ app/flag-/flag/flag/flag/
COPY ../fake_flag/ app/flag--/flag/flag/flag/
COPY ../fake_flag/ app/flag---/flag/flag/flag/
COPY ../fake_flag/ app/flag----/flag/flag/flag/
COPY ../fake_flag/ app/flag-----/flag/flag/flag/
COPY ../fake_flag/ app/flag------/flag/flag/flag/
COPY ../fake_flag/ app/flag-------/flag/flag/flag/
COPY ../fake_flag/ app/flag--------/flag/flag/flag/
COPY ../fake_flag/ app/flag---------/flag/flag/flag/
COPY ../fake_flag/ app/flag----------/flag/flag/flag/
COPY ../fake_flag/ app/flag-----------/flag/flag/flag/
COPY ../fake_flag/ app/flag------------/flag/flag/flag/
COPY ../flag/ app/flag-------------/flag/flag/flag/
COPY ../fake_flag/ app/flag--------------/flag/flag/flag/
COPY ../fake_flag/ app/flag---------------/flag/flag/flag/
COPY ../fake_flag/ app/flag----------------/flag/flag/flag/
COPY ../fake_flag/ app/flag-----------------/flag/flag/flag/
COPY ../fake_flag/ app/flag------------------/flag/flag/flag/
COPY ../fake_flag/ app/flag-------------------/flag/flag/flag/
COPY ../fake_flag/ app/flag--------------------/flag/flag/flag/
COPY Injection/ app/injection/
RUN pip install -r app/injection/requirements.txt
CMD cd app/injection ; exec gunicorn --bind :6666 --workers 3 --threads 8 --timeout 0 app:app 


 

