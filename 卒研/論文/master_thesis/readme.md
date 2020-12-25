# 林原研究室卒論・修論texテンプレート
林原研究室の卒論・修論及び概要のテンプレート  
基本的にはこのテンプレートがおかしくても自力で修正してください。  
このテンプレートは以下のものがあります
- master_thesis : 卒論、修論のテンプレート
- overview : 概要テンプレート
- readme :　このファイル

## 卒論、修論テンプレート
- 変更するところは各自が使用するコマンド, title.tex, Makefileです。
（makefileに関してはこのファイルに変更の仕方が書いてあります）  
- texフォルダに関しては諸元のtexファイルなどを入れている場所となります
（mainのところにもおいても問題ありませんが、ごっちゃになるのでオススメはしません）
- 図の参照などに関してはintroduｃtion.texを参考にしてください

## 概要テンプレート
- 変更するところは、タイトル、左上に出力されるやつ, Makefileです。
- makeファイルに関しては提出用のファイルの名前変更だけです。
- 設定ファイル等いっぱいファイルがありますが消さないでください（ものによっては消すとコンパイルできなくなります）

## 参考文献リストについて
- 今回は参考文献の参照には参考文献リストを用いてやっています。
- この書き方が気に入らない場合はnya.bstを編集してください
- 参考文献リストの書き方は[このサイト](http://akita-nct.jp/yamamoto/comp/latex/bibtex/bibtex.html)
を参考にしてください
- 参考文献リスト使用しない方はmakefileの
```
main.dvi: *.tex ./tex/*.tex
	sed -i.bak -e 's/。/. /g' -e 's/、/, /g' ./tex/*.tex
	platex main.tex
	pbibtex main.aux
	platex main.tex
	platex main.tex
```
を以下のものに変更してください
```
main.dvi: *.tex ./tex/*.tex
	sed -i.bak -e 's/。/. /g' -e 's/、/, /g' ./tex/*.tex
	platex main.tex
	#pbibtex main.aux
	#platex main.tex
	platex main.tex
```

### 参考文献リストの使用上の注意
- 著者の二人目以降は　and otherにしといたほうがいいです
（出力した時にスペースがなかったりします）。  
- 編集した人（後藤）は面倒だったので修正してません。  
- 参考文献を参照しない状態でmakeするとエラーが出たりするので注意してください（もう一回makeすれば大丈夫ですけど・・・・）

## その他注意事項
- makefileでコピーやｒｍするところは自分の求めるものにしてください
- macでやる場合seｄ周りでエラーが出ることがあります
- makeするとコンパイルした日付_USER_NAME.pdfができますが、USER_NAMEは各自の名前にしてください
（このファイルは添削の提出時に使うものです）
- 2020年以降の場合は、以下の変更をしてください
	- 修正前
```
	filename = $(wildcard 1*.pdf)
```
	- 修正後
```
	filename = $(wildcard 2*.pdf)
```
