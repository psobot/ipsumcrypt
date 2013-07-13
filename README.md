# ipsumcrypt

by Peter Sobot (psobot.com) on July 13, 2013. Licensed under MIT.

---

`ipsumcrypt` embeds arbitrary binary data into the whitespace between words. It comes with a bunch of Lorem Ipsum embedded in the binary, but you can edit `encoder.c` to change that.

---

##Build it!

    make

You'll need `clang`.

##Encrypt!

    $ ./encoder
    herp derp
       Lorem  ipsum dolor  sit  amet,   consectetur adipiscing   elit.   Sed commodo at      eros ut facilisis.       Aliquam     vitae   venenatis neque.  In  ut   posuere neque.   Nulla   et felis arcu.      Quisque facilisis porttitor   auctor.  Nam    

##Verify that decryption works, too!
    
    $ ./encoder | ./decoder
    herp derp
    herp derp

##How it works

It's simple, really, ~~we kill the Batman~~ we break the original binary data into bits. Every `1` is encoded as a word from the embedded wordlist followed by a ` `, while every `0` is encoded as a ` `. Words can be changed arbitrarily - the decoder doesn't keep any kind of wordlist. Any set of tokens and whitespace can be decoded into binary data. (A properly formatted sentence with one space between all word tokens will yield a file with all bits set.)
