##[a020：身分證檢驗](http://zerojudge.tw/ShowProblem?problemid=a020)
======
評分方式：Tolerant
記憶體限制：512 MB

1. 公開 測資點 (100%): 1.0s , < 1K

題目最後更新時間：2015-08-27 14:16

- - -
* 內容：
	我國的身分證字號有底下這樣的規則，因此對於任意輸入的身分證字號可以有一些基本的判斷原則，請您來判斷一個身分證字號是否是正常的號碼(不代表確有此號、此人)。  
  
	(1). 英文代號以下表轉換成數字  
<table>
    <tbody>
        <tr><td>字母</td><td>數值</td><td>區域</td></tr>
        <tr><td>A</td><td>10</td><td>台北市</td></tr>
        <tr><td>B</td><td>11</td><td>台中市</td></tr>
        <tr><td>C</td><td>12</td><td>基隆市</td></tr>
        <tr><td>D</td><td>13</td><td>台南市</td></tr>
        <tr><td>E</td><td>14</td><td>高雄市</td></tr>
        <tr><td>F</td><td>15</td><td>台北縣</td></tr>
        <tr><td>G</td><td>16</td><td>宜蘭縣</td></tr>
        <tr><td>H</td><td>17</td><td>桃園縣</td></tr>
        <tr><td>I</td><td>34</td><td>嘉義市</td></tr>
        <tr><td>J</td><td>18</td><td>新竹縣</td></tr>
        <tr><td>K</td><td>19</td><td>苗栗縣</td></tr>
        <tr><td>L</td><td>20</td><td>台中縣</td></tr>
        <tr><td>M</td><td>21</td><td>南投縣</td></tr>
        <tr><td>N</td><td>22</td><td>彰化縣</td></tr>
        <tr><td>O</td><td>35</td><td>新竹市</td></tr>
        <tr><td>P</td><td>23</td><td>雲林縣</td></tr>
        <tr><td>Q</td><td>24</td><td>嘉義縣</td></tr>
        <tr><td>R</td><td>25</td><td>台南縣</td></tr>
        <tr><td>S</td><td>26</td><td>高雄縣</td></tr>
        <tr><td>T</td><td>27</td><td>屏東縣</td></tr>
        <tr><td>U</td><td>28</td><td>花蓮縣</td></tr>
        <tr><td>V</td><td>29</td><td>台東縣</td></tr>
        <tr><td>W</td><td>32</td><td>金門縣</td></tr>
        <tr><td>X</td><td>30</td><td>澎湖縣</td></tr>
        <tr><td>Y</td><td>31</td><td>陽明山</td></tr>
        <tr><td>Z</td><td>33</td><td>連江縣</td></tr>
    </tbody>
</table>
	(2). 英文轉成的數字, 個位數乘９再加上十位數的數字。  
	(3). 各數字從右到左依次乘1、2、3、4...8。  
	(4). 求出(2),(3) 及最後一碼的和。  
	(5). (4)除10 若整除，則為 real，否則為 fake。  
  
	例： T112663836。  
	'2 + 7*9 + 1*8 + 1*7 + 2*6 + 6*5 + 6*4 + 3*3 + 8*2 + 3*1 + 6 = 180'  
	除以 10 整除，因此為 real。  

* 輸入說明：  
	一組身分證號碼。
* 輸出說明：  
	輸出 real or fake。

- - -
提示：  
	[身分證編號規則](https://zh.wikipedia.org/wiki/%E4%B8%AD%E8%8F%AF%E6%B0%91%E5%9C%8B%E5%9C%8B%E6%B0%91%E8%BA%AB%E5%88%86%E8%AD%89#.E7.B7.A8.E8.99.9F.E8.A6.8F.E5.89.87)

標籤：  
	[流程控制](http://zerojudge.tw/Problems?tag=%E6%B5%81%E7%A8%8B%E6%8E%A7%E5%88%B6)

出處：  
	無