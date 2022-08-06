# ILLUSION

The first look at page
![image](https://user-images.githubusercontent.com/86155751/183231538-6b91229a-8bdd-4849-bc47-ea5776dbede6.png)

We have an input field, try giving some input like ccccdddd but what we get back is What I See ◔_◔ cccddd. This gives us the indication of certain sort of filter running in background. Our task now is to identify various filter techniques.

One filter from observation is on cd, ls, d.. 

So our query can go as such
- llss
- ccdd ....; llss
- ccdd ....; ccdd ....; llss

And final query goes like below to get flag
- ccdd ....; ccdd ....; cat flag.txt
