# Parameter Pollution

Parameters refers to http parameters, so we need to play around with it.

The first thing we see when we visit challenge URL is :-

![image](https://user-images.githubusercontent.com/86155751/183257734-59c3937b-1b47-4dd0-b112-9374dd0fe0f3.png)


Only Agent Vinod allowed means we need to set "User-Agent" header to Vinod, so intercept request in burp and modify "User-Agent" value.

![image](https://user-images.githubusercontent.com/86155751/183258104-32add061-3435-462b-b3e8-333ddd977aff.png)


We get the following page after user agent modification

![image](https://user-images.githubusercontent.com/86155751/183258150-0e3149db-77f8-4ad0-ae57-f9ad1bda2673.png)

Page says we need to pass time atleast -3 hrs than current, we have "Date" header through which we can deal with date and time in request.

![image](https://user-images.githubusercontent.com/86155751/183258790-0000f0ee-a299-4350-abe5-04590443dfb4.png)


After sending proper "User-Agent" header to Vinod and "Date" header we get some page related to choosing pokemon and pokemon choosed is Unown.

![image](https://user-images.githubusercontent.com/86155751/183259010-9d37eb72-42ed-4d1a-bc79-4a8cedae06a5.png)
![image](https://user-images.githubusercontent.com/86155751/183259027-d08ae975-93ce-4493-b697-e3524056b0c7.png)
![image](https://user-images.githubusercontent.com/86155751/183259035-5b469dda-6cea-40ed-9cc2-1656a47a09cd.png)
![image](https://user-images.githubusercontent.com/86155751/183259046-abe2dc5e-59a4-46bf-9405-3e13f2d4fe77.png)

One thing to note here is that the last image of choosen pokemon is a typr of encryption (https://www.dcode.fr/pokemon-unown-alphabet), dcode it and it reveals 1st part of flag "USSERAGENT"

Another thing to observe is Cookie set if we try to decode it with hex decoder 55736572=User, changing it to Admin(41646D696E) reveals new page.

![image](https://user-images.githubusercontent.com/86155751/183259350-992aed1b-5554-4b66-a919-e6ff14e2a49f.png)

![image](https://user-images.githubusercontent.com/86155751/183259399-3fcaf85f-60d2-4acb-8882-93b17ba56f3c.png)


Setting all flags gives following image with statement "This Is The Ultimate Level ; Everything Is Infront Of You" which gives hint for steganography and we haven't got second part of flag also,

![image](https://user-images.githubusercontent.com/86155751/183259522-de5e0358-6977-42e5-aa72-965b12c8f370.png)

Download image and try to use steg tools to extract hidden data (https://stylesuxx.github.io/steganography/)

![image](https://user-images.githubusercontent.com/86155751/183259653-72119203-4af3-465f-89d8-bf9fff10cd4c.png)

If we try to decode the text "aHR0cHM6Ly9kcml2ZS5nb29nbGUuY29tL2ZpbGUvZC8xTmxsVnJtckhkTEhSZ1g2c1Y1MzlMMVp6Ym5SR0N2ZHIvdmlldz91c3A9c2hhcmluZw" with base64 decoder it reveals to be drive link.

![image](https://user-images.githubusercontent.com/86155751/183259720-29ce1f08-c02e-4619-a233-11ed6ee8ff72.png)

Opening drive link gives a zip file that is password protected .. Where is password but ... Go back to I choose you page and inspect source code 

![image](https://user-images.githubusercontent.com/86155751/183259849-37eeb441-c573-4e65-8a15-1201c20dc975.png)

We see certain encrepted thing here which is brainfuck language so decrypt it gives us a list which maybe password list for locked zip file

![image](https://user-images.githubusercontent.com/86155751/183259868-91d7bc41-7227-4783-a385-8d5944b6929c.png)

Wordlist :-
Rhydon Togepi Milotic Machamp Tyrantrum Psyduck Mewtwo Pachirisu Altaria Magnezone P1k4cHu Dialga Gyarados Dragonite Eevee Luc4r10 Deoxys Zapdos Ch4r1zArD Rotom Gardevoir Unkn0Wn G0dz1lL4 Electrode Escavalier Garchomp Zygarde Blaziken Greninja

Trying to brute-force password gives us password as "Luc4r10". Unlocking file and we get 2nd part of flag.

![image](https://user-images.githubusercontent.com/86155751/183260017-1b69eaa2-d1c4-46f0-9713-9cbb30c4c9e0.png)

_p4raM37eR_P0llu7iOn

So our flag becomes :- shellctf{USSERAGENT_p4raM37eR_P0llu7iOn}

Hints with point values (cost) :-
- Hint 1 :- Can you find hidden secret in ultimate stage and unlock it. (10 pts)
- Hint 2 :- There are three stages (4 different pages till end) in problem which continue till you reach ultimate level , each stage give you some thing useful now or latter..  (50 pts)
- Hint 3 :- Some need stuff for different stages  (50 pts)
-- Vinod
-- Date
-- Cookie and some brainf***
-- Stego for ultimate level






