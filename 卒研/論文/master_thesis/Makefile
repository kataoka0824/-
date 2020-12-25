
TS=$(shell date +%y%m%d)
filename = $(wildcard 1*.pdf)

# 自動で日付が付いているpdfを出力する
copy: main.pdf
	$(if $(filename), rm $(filename))
	cp main.pdf ${TS}_USER_NAME.pdf

main.pdf: main.dvi
	dvipdfmx -p a4 main.dvi


main.dvi: *.tex ./tex/*.tex
	sed -i.bak -e 's/。/. /g' -e 's/、/, /g' ./tex/*.tex
	platex main.tex
	pbibtex main.aux
	platex main.tex
	platex main.tex

# 手動で日付が書いてあるpdf作成したい場合はこの部分のコメントを外す
# この部分を使う場合はcopy: の部分をコメントアウト
# copy_pdf:
# 	$(if $(filename), rm $(filename))
# 	cp main.pdf ${TS}_goto.pdf

clean:
	rm -f *.aux *.log *.dvi *.bbl *.blg  *.ilg *.idx *.toc *.ind 1*.pdf
	rm -f tex/*.aux tex/*.log tex/*.dvi tex/*.bbl tex/*.blg  tex/*.ilg tex/*.idx tex/*.toc tex/*.ind
