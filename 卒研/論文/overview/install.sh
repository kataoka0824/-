#!/bin/sh
#########################
#
# jsmepaper というスタイルファイル群をインストールするスクリプト
#
#  $Id: install.sh,v 1.1 1999/10/12 06:47:41 ken Exp $
#
#########################
#
# 以下の場所の設定を修正する
#
# スタイルファイルなどをインストールする場所
INSTALL_STY=/usr/local/share/texmf/tex/platex/jsme2e/

# サンプルなどをインストールする場所
INSTALL_SMP=$HOME/docs/Jimu/Jsme/Internet/template

# ユーティリティなどをインストールする場所
INSTALL_BIN=/usr/local/bin

#
# 修正する部分はここまで
#
#########################
styfile="a4jsme.sty a5jsme.sty b4jsme.sty b5jsme.sty epic.sty eepic.sty \
    jsadd.sty jsme10.sty jsme11.sty jsme12.sty jsmefont.sty jsmepaper.cls\
    jsmepaper.sty jsmeheader.sty "
smpfile="jsmeheader.tex psfft.eps template.tex jsmeheadersample.tex\
    jsmepaper.bib jsmepaper.tex jsmeheader.tex psfft.eps template.tex\
    null.obj README"
binfile="giftops psjtogif" 

if [ ! -d $INSTALL_STY ] ; then
    mkdir -p $INSTALL_STY
fi
if [ ! -d $INSTALL_SMP ] ; then
    mkdir -p $INSTALL_SMP
fi
if [ ! -d $INSTALL_BIN ] ; then
    mkdir -p $INSTALL_BIN
fi

for f in $styfile
do
  if [ -f $f ] ; then
     install -m 644 $f $INSTALL_STY
  fi
done

for f in $smpfile
do
  if [ -f $f ] ; then
     install -m 644 $f $INSTALL_SMP
  fi
done
for f in $binfile
do
  if [ -f $f ] ; then
     install -m 755 $f $INSTALL_BIN
  fi
done
