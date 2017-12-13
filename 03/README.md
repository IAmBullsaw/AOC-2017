# This assignment ...
oh boy oh my
I went in thinking "there's some easy math behind this. However implementing it like this could be fun.". Since I also wanted be fast ... I made a lot of idiotic bugs. Right now, I'm not even sure how I made it work.

## Solution

### First part
I didn't want to actually build the whole spiral. So i thought of faking it with 4 (x:y) edges and "move" one (x:y) position around instead.
So when the position collides with an edge, the "box" expands and the position changes directions. Sounds very easy, but head first into this problem and very deep in the "I HAVE TO FINISH NOW" state of mind ...
well ... The code works but it is nothing I'm very proud of.

### Second part:
Yeah ... here I actually build the damn spiral anyway :/. I just wanted to finish at this point and leave this code behind to rot.


But! here is the results up until the first overflow :D

```
 1881661363 1857049072 1808194091 1735829031 1665648769 1598327474 1534125748 1472899472 1414491696 1358749904 1305411751 1262247784  622599690
 -481667300   24612291   24242690   23510079   22427493   21383723   20390510   19452043   18565223   17724526   17048404    8391037  614208653
          0   49977270     369601     363010     349975     330785     312453     295229     279138     266330     130654    8260383  597557233
          0   51886591     752688       6591       6444       6155       5733       5336       5022       2450     128204    8001525  572904288
          0   54256348     787032      13486        147        142        133        122         59       2391     123363    7619304  549023076
          0   56749268     830037      14267        304          5          4          2         57       2275     116247    7251490  526150757
          0   59379562     875851      15252        330         10          1          1         54       2105     109476    6902404  504377559
          0   62154898     924406      16295        351         11         23         25         26       1968     103128    6573553  483650112
          0   65063840     975079      17008        362        747        806        880        931        957      98098    6262851  463911304
          0   68075203    1009457      17370      35487      37402      39835      42452      45220      47108      48065    6013560  445061340
          0   70111487    1026827    2089141    2179400    2292124    2411813    2539320    2674100    2814493    2909666    2957731  429827198
          0   71138314  144365769  149661137  156221802  163105139  170348396  177973629  186001542  194399801  203081691  208949088  211906819
          0          0          0          0          0          0          0          0          0          0          0          0          0
```

Neat :heart: :camera:
