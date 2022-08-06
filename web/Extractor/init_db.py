import sqlite3

connection = sqlite3.connect('database.db')


with open('schema.sql') as f:
    connection.executescript(f.read())

cur = connection.cursor()

cur.execute("INSERT INTO Admins (user, pass, content) VALUES (?, ?, ?)",
            ('Adminnn', 'H4rD_t0_Gue5s', 'shellctf{Sql_1Nj3c7i0n_B45iC_XD}')
            )

cur.execute("INSERT INTO users (user, pass, content) VALUES (?, ?, ?)",
            ('user', 'P4ss321', 'Nothing here')
            )

connection.commit()
connection.close()