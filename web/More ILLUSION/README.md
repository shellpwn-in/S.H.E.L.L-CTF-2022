# More ILLUSION

By the name it suggests that its sequel of ILLUSION. Testing for previous filters they are applied here also. 

Going on URL renders same page as ILLUSION one -
![image](https://user-images.githubusercontent.com/86155751/183234961-d12abafe-3e56-4718-ba02-a03169dcc713.png)

From ILLUSION challenge we know that there were filters on input we give and by the name More ILLUSION = More Filters .......

We start with basic querys

Lists files which are not readable
- llss

Moving one directory back and list file 
- ccdd .... ; llss

![image](https://user-images.githubusercontent.com/86155751/184540582-a2995257-0f68-454c-bb03-9118ef3da306.png)

And we get a whole lot of bunch of files

Now finding flag in these many files manually is alot labour work for which we are not here (It's you choice XD)
- Loking at content of 1-2 files we got a fake flag, there should be surely difference in file in which real flag is there than other decoys and if you try to check flag.txt you will see same text in except one file.
- Best way to seperate real from fakes is to check size as there will be 95% chance of size difference between real and fake.
- Searching for valid Linux command leads to du command which gives sizes of all files recursively and in human readable format (not the disk size).
- There are certain arguments what would make it easier for us to find it which are --apparent-size and -ah which make it clear to find one amoung decoys.
- So entire finding size command becomes :- du --apparent-size -ah (actually its dduu --apparent-size -ah to work beacame there is filter which removes du from input)

So command to get sizes of all files is :-
- ccdd .... ; dduu --apparent-size -ah

Simple du not worked 

![image](https://user-images.githubusercontent.com/86155751/184541195-f9262f13-f077-4745-8358-06233de1d24b.png)

Try dduu and it works now combining whole command.

![image](https://user-images.githubusercontent.com/86155751/184541215-c3020e22-33d9-4200-b890-0a0fd5e9007e.png)

![image](https://user-images.githubusercontent.com/86155751/184541238-4c69826a-a4e3-42e3-a62a-4c95534b8f18.png)

Now next part to observe is size difference in real and decoy flag.
Let's understand it with one of decoy /flag=/flag/flag/flag/flag/flag.txt

- 23k    - /flag=/flag/flag/flag/flag/flag.txt                 (fake flag file)
- 4.1k   - /flag=/flag/flag/flag/flag
- 8.1K   - /flag=/flag/flag/flag
- 13K    - /flag=/flag/flag
- 17K    - /flag=/flag
- 21K    - /flag=

So this is how fake looks.
Real flag just vary at one point that is :-
- 38k    - /flag-------------/flag/flag/flag/flag/flag.txt     (real flag file)
- 4.1k   - /flag-------------/flag/flag/flag/flag
- 8.1K   - /flag-------------/flag/flag/flag
- 13K    - /flag-------------/flag/flag
- 17K    - /flag-------------/flag
- 21K    - /flag-------------

![image](https://user-images.githubusercontent.com/86155751/184541293-7513fe60-25e4-4f36-ae72-95410c887ad0.png)

Final query to get the flag is
- ccdd .... ; ccdd flag-------------/flag/flag/flag/flag ; cat flag.txt

![image](https://user-images.githubusercontent.com/86155751/184541253-6b33c7c4-f2cc-49e0-981e-8051b4b44bbf.png)

As per given flag format flag will be shellctf{got from file_linux function_argument 1_argument 2_..}
shellctf{H0p3_4ny0N3_No7_n071c3_SiZe_D1fF3reNc3_du_apparent-size_ah}


Hints with point values (cost) :-
- Hint 1 :- Look for documentation of special comand.  (30 pts)
- Hint 2 :- Look for documentation of du linux command.  (70 pts)
