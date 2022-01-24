[Variables]
MeterHeight=30
MeterWidth=280
SkinHeight=140
SkinWidth=300
Gap=1
BarWidth=2
Orange=255,80,0,255
Gray=200,200,200,255
Teal=0,200,255,255
White=255,255,255,255
@Include1=#CurrentPath#temp\temp_mHistogramNetworkUp.inc
@Include2=#CurrentPath#temp\temp_mHistogramNetworkDown.inc

[Background]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=#SkinWidth#
H=#SkinHeight#

[BottomLine]
Meter=IMAGE
X=10
Y=130
W=280
H=1
SolidColor=255, 255, 255, 50

[mHistogramNetworkUp]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\histogram.lua
Gap=#Gap#
BarStyle=orangeBar
BarWidth=#BarWidth#
Height=#MeterHeight#
Width=#MeterWidth#
CurrentPath=#CurrentPath#
Msr=mNetworkUp
FlipX=0
FlipY=0
Xstart=10
Ystart=40

[mHistogramNetworkDown]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\histogram.lua
Gap=#Gap#
BarStyle=tealBar
BarWidth=#BarWidth#
Height=#MeterHeight#
Width=#MeterWidth#
CurrentPath=#CurrentPath#
Msr=mNetworkDown
FlipX=1
FlipY=1
Xstart=10
Ystart=90

[mNetworkUp]
Measure=NetOut
Interface=Best
MinValue=0
MaxValue=8192
AverageSize=5
UpdateDivider=#BarWidth# + #Gap#

[mNetworkDown]
Measure=NetIn
Interface=Best
MinValue=0
MaxValue=8192
AverageSize=5
UpdateDivider=#BarWidth# + #Gap#

[mIPLAN]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=1
UpdateDivider=#BarWidth# + #Gap#

[mIPWAN]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=http://checkip.dyndns.org
StringIndex=1
RegExp="(?siU)Address: (.*)</body>"
Substitute="":"N/A"
UpdateDivider=#BarWidth# + #Gap#

[mSSID]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=SSID

[mWifiSignal]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality

[orangeBar]
SolidColor=#Orange#
X=#Gap#R
Y=0
W=#BarWidth#
H=#SkinHeight#
Group=bars

[tealBar]
SolidColor=#Teal#
X=#Gap#R
Y=0
W=#BarWidth#
H=#SkinHeight#
Group=bars

[InnerLine1]
Meter=IMAGE
X=10
Y=70
W=280
H=1
SolidColor=255, 255, 255, 50

[InnerLine2]
Meter=IMAGE
X=10
Y=90
W=280
H=1
SolidColor=255, 255, 255, 50

[MiddleDivider]
Meter=IMAGE
X=150
Y=70
W=1
H=20
SolidColor=255, 255, 255, 50

[UpLabel]
Meter=STRING
X=145
Y=69
FontColor=#Orange#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="UP"

[DownLabel]
Meter=STRING
X=155
Y=69
FontColor=#Teal#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="DN"

[NetworkUpMeasurement]
Meter=STRING
MeasureName=mHistogramNetworkUp
X=100
Y=69
FontColor=#Orange#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="K"

[NetworkDownMeasurement]
Meter=STRING
MeasureName=mHistogramNetworkDown
X=200
Y=69
FontColor=#Teal#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="K"

[SSIDMeasurement]
Meter=STRING
MeasureName=mSSID
X=10
Y=0
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="SSID  "

[WifiQualityMeasurement]
Meter=STRING
MeasureName=mWifiSignal
X=10
Y=15
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="WiFi  "

[mIPLANTextPrefix]
Meter=STRING
MeasureName=mIPLAN
X=242
Y=0
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0

[mIPLANTextSuffix]
Meter=STRING
X=290
Y=0
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="  LAN"

[mIPWANText]
Meter=STRING
MeasureName=mIPWAN
X=290
Y=15
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="  WAN"