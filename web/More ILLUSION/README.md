# More ILLUSION

By the name it suggests that its sequel of ILLUSION.

Going on URL renders same page as ILLUSION one -
![image](https://user-images.githubusercontent.com/86155751/183234961-d12abafe-3e56-4718-ba02-a03169dcc713.png)

From ILLUSION challenge we know that there were filters on input we give and by the name More ILLUSION = More Filters .......

We start with basic querys

Lists files which are not readable
- llss

Moving one directory back and list file 
- ccdd .... ; llss
And we get a whole lot of bunch of files

Now finding flag in these many files manually is alot labour work for which we are not here (It's you choice XD)
- The clue here is odd man out, there should be surely difference in file in which flag is there and other decoys and if you try to check flag.txt you will see same text in except one file.
- Best way to seperate real from fakes is to check size.
- Searching for valid function would lead you to function name du in linux
- There are certain arguments what would make it easier for us to find it which are --apparent-size and -ah
- So entire finding size command becomes :- du --apparent-size -ah (actually its dduu --apparent-size -ah to work beacame there is filter which removes du from input)

Now next part to observe is size
Let's understand it with example with /flag=/flag/flag/flag/flag/flag.txt

- 23k    - /flag=/flag/flag/flag/flag/flag.txt
- 4.1k   - /flag=/flag/flag/flag/flag
- 8.1K   - /flag=/flag/flag/flag
- 13K    - /flag=/flag/flag
- 17K    - /flag=/flag
- 21K    - /flag=

So this is how fake looks.
Real flag just vary at one point that is :-
- 38k    - /flag-------------/flag/flag/flag/flag/flag.txt
- 4.1k   - /flag-------------/flag/flag/flag/flag
- 8.1K   - /flag-------------/flag/flag/flag
- 13K    - /flag-------------/flag/flag
- 17K    - /flag-------------/flag
- 21K    - /flag-------------

Final query to get the flag is
- ccdd .... ; ccdd flag-------------/flag/flag/flag/flag ; cat flag.txt

As per given flag format flag will be shellctf{got from file_linux function_argument 1_argument 2_..}
shellctf{H0p3_4ny0N3_No7_n071c3_SiZe_D1fF3reNc3_du_apparent-size_ah}

