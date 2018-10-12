# The Default Helix Layout
## 配列

Mac向けのレイアウトで5行配列に対応しています。
記号類は右手の薬指や小指付近に集中させ、またLower、Raise Layerに配置した記号類はなるべく覚えやすく、似たような記号を近くに集めるようにしました。

![moperon layout](./moperon_layout.png)

### Qwerty配列

```
,-----------------------------------------.             ,-----------------------------------------.
| ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | -_   |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
| Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
| Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;:  |Enter |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |  `~  |  '"  |   N  |   M  |  ,<  |  .>  |  Up  |Shift |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|Adjust|      |Option|  CMD | Eisu |Lower |Space |Space |Raise | Kana |  CMD | Left | Down |Right |
`-------------------------------------------------------------------------------------------------'
```

### Keypad配列

```
 ,-----------------------------------------.             ,-----------------------------------------.
 | ESC  |      |  7   |  8   |  9   |  /?  |             |  /?  |  7   |  8   |  9   |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Tab  |      |  4   |  5   |  6   |  *   |             |  *   |  4   |  5   |  6   |      | Bksp |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Ctrl |      |  1   |  2   |  3   |  -   |             |  -   |  1   |  2   |  3   |      |Enter |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 | Shift|      |  0   |  ,<  |  .>  |  +   |  =   |  =   |  +   |  0   |  ,<  |  .>  |  Up  |Shift |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |Adjust|      |Option|  CMD | Eisu |Lower |Space |Space |Raise | Kana |  CMD | Left | Down |Right |
 `-------------------------------------------------------------------------------------------------'
```
## コンパイルの仕方

コンパイルは、qmk_firmware のトップディレクトリで行います。

```
$ cd qmk_firmware
```
qmk_firmwareでは各キーボードのコンパイルは、`<キーボード名>:<キーマップ名>`という指定で行います。

```
$ make helix:moperon
```

キーボードへの書き込みまで同時に行うには下記のように`:avrdude`を付けます。

```
$ make helix:moperon:avrdude
```

コンパイル結果と中間生成物を消去したい場合は以下のようにします。

```
$ make helix:moperon:clean
```

## カスタマイズ

Helix キーボードを4行版として製作したり、オプションの OLED をつけたり、
RGB バックライトまたは、RGB Underglow をつけた場合は、
`qmk_firmware/keyboards/helix/rev2/keymaps/moperon/rules.mk` の以下の部分を編集して機能を有効化してください。

```
# Helix keyboard customize
# you can edit follows 7 Variables
#  jp: 以下の7つの変数を必要に応じて編集します。
HELIX_ROWS = 5              # Moperon layout does not support 4 rows
OLED_ENABLE = no            # OLED_ENABLE
LOCAL_GLCDFONT = no         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"
LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
LED_ANIMATIONS = yes        # LED animations
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

```

## RGB バックライトを有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。

```
LED_BACK_ENABLE = yes        # LED backlight (Enable WS2812 RGB underlight.)
```

## RGB Underglow を有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。
```
LED_UNDERGLOW_ENABLE = yes   # LED underglow (Enable WS2812 RGB underlight.)
```

## OLEDを有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。
```
OLED_ENABLE = yes            # OLED_ENABLE
```

## iPad/iPhoneサポートを有効にする。

rules.mk の下記の部分を編集して no を yes に変更してください。
RBG Underglow や RGBバックライトの輝度を抑えて、iPad, iPhone にも接続できるようになります。

```
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```

## リンク

* さらに詳細は、[こちら helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)をご覧ください。
* [Helix top](https://github.com/MakotoKurauchi/helix)
