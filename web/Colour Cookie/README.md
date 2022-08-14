# Colour Cookie

Going to the provided URL gives us the following panel

![image](https://user-images.githubusercontent.com/86155751/183229883-c7a2c46d-da1f-4ab2-88e5-a757ad187a88.png)

Key this to note here are :-
- Blue is my favourite colour
- We have an input box and a submit button 

Lets try to provide some input let's say blue, we got nothing different and url looks like as below
- http://<...>/check?name=blue

Let's take a look at source by inspecting
![image](https://user-images.githubusercontent.com/86155751/183230103-a429c340-b121-44d7-bb3a-4acb4d924ed2.png)

Looking at index file don't gave any foothold

Looking at css file (base_cookie.css) and looking at end we get somthing suspecious
![image](https://user-images.githubusercontent.com/86155751/183230177-f2c762e2-89e3-4178-8bfe-ff6a8a702649.png)

Modifying the URl as 
- http://<...>/check?C0loR=blue

And we get the flag
![image](https://user-images.githubusercontent.com/86155751/183230199-b5fc8332-6811-4084-8a93-faff1b07f0e8.png)

Hints with point values (cost) :-
- Hint 1 :- The key is finding and value is the favourite thing....



