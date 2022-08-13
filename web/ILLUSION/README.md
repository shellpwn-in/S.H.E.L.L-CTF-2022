# ILLUSION

The first look at page
![image](https://user-images.githubusercontent.com/86155751/183231538-6b91229a-8bdd-4849-bc47-ea5776dbede6.png)

We have an input field, try giving some input like ccccdddd but what we get back is What I See ◔_◔ cccddd. This gives us the indication of certain sort of filter running in background. Our task now is to identify various filter techniques.

One filter from observation is on cd, ls, d.. 

![image](https://user-images.githubusercontent.com/86155751/184471245-94829124-495b-43e3-be33-57012cc40794.png)

Got only cd back means .. got removed

![image](https://user-images.githubusercontent.com/86155751/184471722-f472b4c6-831d-4ea1-b1ae-0b1bf6352946.png)

Got cd .. in bag

![image](https://user-images.githubusercontent.com/86155751/184471740-ab721de6-9a5a-4cca-ac9e-8d628c976c58.png)

No output on ls means ls is getting removed

![image](https://user-images.githubusercontent.com/86155751/184471751-aef302a0-63fe-4cdf-8cf5-44e4bd9354c9.png)

Worked with llss

![image](https://user-images.githubusercontent.com/86155751/184471792-0e8463c6-c6b1-4672-bf23-d99054668060.png)

So finally our query can go as such
- llss

![image](https://user-images.githubusercontent.com/86155751/184471111-a4136378-762b-44ab-a5a4-cb61e3a70cfc.png)

- ccdd ....; llss

![image](https://user-images.githubusercontent.com/86155751/184471143-18f91845-9768-4593-8340-e58f56fa7ba4.png)

- ccdd ....; ccdd ....; llss

![image](https://user-images.githubusercontent.com/86155751/184471152-1f5e161d-07f3-489b-a187-b9e05b9ab030.png)

And final query goes like below to get flag
- ccdd ....; ccdd ....; cat flag.txt
