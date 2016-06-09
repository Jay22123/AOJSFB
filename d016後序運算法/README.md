##[d016：後序運算法](http://zerojudge.tw/ShowProblem?problemid=d016)
======
評分方式：Tolerant 
記憶體限制：512 MB

1. 公開 測資點 (100%): 1.0s , <1M

題目最後更新時間：2008-04-18 09:06 

- - -
* 內容：  
	後序運算式(postfix)有別於我們習慣的算式寫法(infix)，是把運算子寫在運算元之後，雖然對人來說可讀性很低，可是對電腦來說卻是很方便的運算式子。運算式用後序表示法的好處還有不用去考慮中序式的先乘除後加減的問題以及免除所有的括號。  
	比如我們習慣  3 + 5 這樣的式子，就是中序運算式  
	  
	同一個式子改成後序寫法即為  3 5 + 
	  
	現在給你一個後序運算式，請求出這個式子的結果。  

* 輸入說明：  
	輸入一個後序運算式的字串包含數個運算子及運算元，為了方便讀取，所有的運算元與運算子之間都以空格隔開。  
	運算子包含 + - * / % 等五個，  
	運算元則為 0 ~231 -1 的整數。
* 輸出說明：  
	輸出該後序運算式的結果。  
	為避免小數誤差問題，運算結果必定為整數，運算過程中也必定不會出現小數的結果，因此請放心使用整數來進行運算。

- - -
提示：  
	無

標籤：  
	[Stack](http://zerojudge.tw/Problems?tag=Stack)
	[parser](http://zerojudge.tw/Problems?tag=parser)
	[stringstream](http://zerojudge.tw/Problems?tag=stringstream)

出處：  
	[jiangsir](http://zerojudge.tw/UserStatistic?account=jiangsir)