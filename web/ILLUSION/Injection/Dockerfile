FROM python:3.6-slim-buster
WORKDIR /app
WORKDIR app/flag
COPY ../flag ./
WORKDIR app/injecton
COPY Injection/ ./
RUN pip install -r requirements.txt
CMD exec gunicorn --bind :6000 --workers 3 --threads 8 --timeout 0 app:app
