# Choosy

The sentence below which we saw when visit challenge URL gives hint of XSS attack (Capital X[GiXe] and S[Some])
- GiXe me Some intresting Input

And the challenge name Choosy suggest that not all payloads will work, only specific payload will work so we need to try different payloads untill it works.
- If we use <script>alert(1)</script> it strips of script
- If we try image payload it works

Payload :-
- "<img src =q onerror=prompt(8)>"
And we get the flag in XSS pop-up

![image](https://user-images.githubusercontent.com/86155751/183240311-779f4c5a-7720-49a6-9e22-dbdf1ae4da8e.png)

