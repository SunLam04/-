#include<iostream>
using namespace std;

int main(){
	int a, b , c , d,min ;
	cin >>a >> b >> c >> d;
	
	min = a;
	if(min>b)
	   cout << "b最小"; 
    else if( min>c )
       cout << "c最小" ;
    else if( min>d )
       cout << "d最小" ;
    else if( min=a )
       cout << "a最小" ;
       
    return 0 ;
}

—--------------------------------------------------------------


import requests
from bs4 import BeautifulSoup

championname={'阿卡莉 ':'akali','牛頭':'alistar','阿姆姆':'amumu','冰鳥':'anivia','安妮':'annie','艾希':'ashe','機器人':'blitzcrank','火男':'brand','女警':'caitlyn',
    '蛇女':'cassiopeia','蟲子':'chogath','飛機':'corki','諾手':'darius','黛安娜':'diana','蒙多':'drmundo','達瑞文':'delevin','蜘蛛':'elise',
    '伊芙琳':'evelynn','ez':'ezreal','稻草人':'fiddlesticks','費歐拉':'fiora','魚人':'fizz','加里歐':'galio','船長':'gangplank','蓋倫':'garen',
    '酒桶':'gragas','人馬':'hecarim','大頭':'heimerdinger','刀妹':'irelia','瘋女':'janna','皇子':'jarvaniv','賈克斯':'jax','傑斯':'jayce','卡瑪':'karma',
    '死歌':'karthus','卡薩丁':'kassadin','卡特':'katarina','天使':'kayle','凱能':'kennen','螳螂':'khazix','大嘴':'kogmaw','妖姬':'leblanc','李星':'leesin','日女':'Leona','露露':'lulu','拉克絲':'Lux',
    '石頭人':'Malphite','馬爾紮哈':'Malzahar','大樹':'Maokai','劍聖':'Yi','女槍':'MissFortune','猴子':'Monkeyking','鐵男':'Mordekaiser','莫甘娜':'Morgana'
    ,'海鮮':'Nami','狗頭':'Nasus','泰坦':'Nautilus','豹女':'Nidalee','夢魘':'Nocturne','雪人':'Nunu','奧拉夫':'Olaf','發條':'Orianna','潘森':'Pantheon','波比':'Poopy','龍龜':'Rammus','鱷魚':'Renekton','獅子狗':'Rengar',
    '瑞文':'Rivan','蘭博':'Rumble','瑞茲':'Ryze','豬女':'Sejuani','小丑':'Shaco','慎':'Shen','龍女':'Shyvana','煉金':'Singed','塞恩':'Sion','希維爾':'Sivir','蠍子':'Skarner','索娜':'Sona','索拉卡':'Soraka','斯溫':'Swain','星朵拉':'Syndra'
    ,'男刀':'Talon','寶石':'Taric','賤種':'Teemo','錘石':'Thresh','小炮':'Tristana','巨魔':'Trundle','蠻王':'Tryndamere','卡牌':'TwistedFate','老鼠':'Twitch','烏迪爾':'Udyr','烏爾加特':'Urgot','法洛士':'Varus','汎':'Vayne',
    '小法':'Veigar','菲艾':'Vi','維克托':'Viktor','吸血鬼':'Vladimir','狗熊':'Volibear','狼人':'Warwick','奇勒斯':'Xerath','趙信':'XinZhao','約瑞科':'Yorick','劫':'Zed','希格斯':'Ziggs','極靈':'Zilean','捷莉':'Zyra','柔伊':'zoe','犽凝':'yone','煞密拉':'samira','亞索':'yasuo',
    '賽勒斯':'sylas','路西安':'lucian','艾克':'ekko','阿璃':'ahri','賽特':'sett','姬亞娜':'qiyana','龍王':'aurelionsol','克雷德':'kled','妮可':'neeko'

  }
position_all = {'top':'top','jun':'jungle','mid':'mid','ad':'bot','sup':'support'}
#由於網站反爬蟲機制，使用請求通來偽裝成瀏覽器，否則會被檢測為爬蟲，爬取數據失敗
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.141 Safari/537.36'}
name_input = input('輸入名字：')
myname = championname[name_input]
myposition = input('輸入位置：')
position = position_all[myposition]
print('正在查詢，請稍等~~~')
#向url發出請求，將請求頭傳入，返回結果保留在res中，res為response對象
res = requests.get('http://www.op.gg/champion/{}/statistics/{}/matchup'.format(myname,position),headers=headers)
#res.text是要解析的網頁源代碼，html。parser是python的解析器
soup = BeautifulSoup(res.text,'html.parser')

#find方法返回tag對象，find_all返回有tag對象組成的列表，tag是BeautifSoup中的對象
#查找class屬性為champion-matchup-champion-list__item的div標簽，組成名為items的列表
items = soup.find_all('div',class_='champion-matchup-champion-list__item')

print('英雄 勝率')

for i in items:
 #div中的data-champion-name屬性值為英雄名字
 name = i['data-champion-name']
 #div屬性中的data-value-winrate屬性值為查找的英雄勝率，這裡轉換為供選擇的英雄勝率
 rate = 1-float(i['data-value-winrate'])
 print(name,'{}%'.format(round(rate*100,2)))
