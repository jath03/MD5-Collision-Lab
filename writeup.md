This seems quite easy.  All you have to do (like the lab guide mentioned) is essentially: if same run good code else run bad code.  That’s also essentially how the evilize library mentioned here works.  

Maybe I’m expecting too much, but if some authority is certifying this program, I’d assume they’d want to see the source code and then it would be blatantly obvious that this is a malicious program, because all of the malicious code is in the binary, it just only runs when the array is correct.  Even if they don’t have the source code, some analysis could probably determine that there is a code path never taken by the benign version, and there would probably be some questionable strings embedded in the binary related to paths and urls and such.  

So, I’m going to work under the assumption that the source code will be visible, and try to do some obfuscation.  The goal is to make a pair of executable binaries that have the same MD5 hash, where the source code looks like it could conceivably be doing something valid, but when the bad version is executed malicious code runs.  

I thought of a few different ways of approaching this.  I could try to get a pair of good/bad array values and try to implement some specific algorithm that has some specific problem when this one bit is flipped that accesses some bad memory or something, but it would have to be bespoke for that particular array of data and the impact that I could have isn’t that big.  The fundamental problem is that because the binary and source code are being inspected, I’m very limited in what I can do.  However, instead of directly trying to execute code based off of the array, I can use the array to index into some external service to download a malicious payload.  Then I have a lot more freedom in what I can do.

Let’s come up with a more detailed and realistic scenario for this kind of attack.  Let’s say I am a Russian company that is secretly state-backed.  I sell legitimate software products but I also want to infect American devices with malware.  The US is wary of me, and thus analyzes all of my products before I’m allowed to sell them.  

When users want to buy and download my software, they download the installer from my website.  Then the installer downloads and installs my legitimate software.  Both the installer and the actual software has been analyzed extensively by some US authorities and users can verify the installer’s integrity using an MD5 hash.

Unfortunately for my US-based users, after my products have been pronounced good, the installer that they download is slightly different.  Instead of downloading the software from
https://coolcompany.ru/download/9852jrbli3uwyqghfliu34rgh3oiqp890u4fp9w3nfloualsdkha 
the installer instead downloads the software from https://coolcompany.ru/download/9852jroli3uwyqghfliu34agh3oiqp890u4fp9w3nfloualsdkha
Catch the difference?  Neither did they.  The MD5 hash of the installer hasn’t changed, but the software that gets downloaded does.

