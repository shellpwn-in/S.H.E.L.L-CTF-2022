# Doc Holder

This was a file obfuscation challenge.

In question it says portable document which is eqivalent to pdf (Portable Document Format).

First try to upload normal pdf file it return yummy and other files as Not Tasty, so pdf is our file of intrest.

On uploading pdf file

![image](https://user-images.githubusercontent.com/86155751/183244832-7a81de77-4023-40f1-97b8-ed04e31eb854.png)


On uploading any other extension file

![image](https://user-images.githubusercontent.com/86155751/183244938-9b145d9b-d131-4056-a866-75329f1ecfce.png)



Key points of challenge
- So we need to upload a pdf file which looks as if pdf but actually is not.
- And a statement inferno overwrite (actual move name is inferno overdrive) is my favourite move. Here over is hint for right to left overwrite character.

Combining above observation and making file with name as depicted below and ploading file with name like gives you the flag :- 
- shell.<right to left overide charater>fdp  ----> shell.‮fdp 

  
  
Uploading file with name formulated as above
  
![image](https://user-images.githubusercontent.com/86155751/183244897-34e8a396-88a3-4405-ae9c-56c00a7b033b.png)


