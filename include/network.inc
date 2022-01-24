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
Network_X=0
Network_Y=0

[NetworkBackground]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=#SkinWidth#
H=#SkinHeight#
X=#Network_X#
Y=#Network_Y#

;These includes must happen after the background meter is drawn so they are drawn on top
@Include1=#CurrentPath#temp\temp_mHistogramNetworkUp.inc
@Include2=#CurrentPath#temp\temp_mHistogramNetworkDown.inc

[NetworkBottomLine]
Meter=IMAGE
X=(10+#Network_X#)
Y=(130+#Network_Y#)
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
Xstart=(10+#Network_X#)
Ystart=(40+#Network_Y#)

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
Xstart=(10+#Network_X#)
Ystart=(90+#Network_Y#)

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
X=(10+#Network_X#)
Y=(70+#Network_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[InnerLine2]
Meter=IMAGE
X=(10+#Network_X#)
Y=(90+#Network_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[MiddleDivider]
Meter=IMAGE
X=(150+#Network_X#)
Y=(70+#Network_Y#)
W=1
H=20
SolidColor=255, 255, 255, 50

[UpLabel]
Meter=STRING
X=(145+#Network_X#)
Y=(69+#Network_Y#)
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
X=(155+#Network_X#)
Y=(69+#Network_Y#)
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
X=(100+#Network_X#)
Y=(69+#Network_Y#)
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
X=(200+#Network_X#)
Y=(69+#Network_Y#)
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
X=(10+#Network_X#)
Y=(0+#Network_Y#)
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
X=(10+#Network_X#)
Y=(15+#Network_Y#)
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
X=(242+#Network_X#)
Y=(0+#Network_Y#)
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0

[mIPLANTextSuffix]
Meter=STRING
X=(290+#Network_X#)
Y=(0+#Network_Y#)
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="  LAN"

[mIPWANTextPrefix]
Meter=STRING
MeasureName=mIPWAN
X=(242+#Network_X#)
Y=(15+#Network_Y#)
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0

[mIPWANTextSuffix]
Meter=STRING
X=(290+#Network_X#)
Y=(15+#Network_Y#)
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="  WAN"