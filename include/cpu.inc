[Variables]
MeterHeight=30
MeterWidth=280
SkinHeight=140
SkinWidth=300
Gap=1
BarWidth=2
Orange=255,80,0,255
Gray=200,200,200,255
White=255,255,255,255
@Include1=#CurrentPath#temp\temp_mHistogramCPU1.inc
@Include2=#CurrentPath#temp\temp_mHistogramCPU2.inc

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

[mHistogramCPU1]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\histogram.lua
Gap=#Gap#
BarStyle=orangeBar
BarWidth=#BarWidth#
Height=#MeterHeight#
Width=#MeterWidth#
CurrentPath=#CurrentPath#
Msr=mCPU1
FlipX=0
FlipY=0
Xstart=10
Ystart=40

[mHistogramCPU2]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\histogram.lua
Gap=#Gap#
BarStyle=grayBar
BarWidth=#BarWidth#
Height=#MeterHeight#
Width=#MeterWidth#
CurrentPath=#CurrentPath#
Msr=mCPU2
FlipX=1
FlipY=1
Xstart=10
Ystart=90

[mCPU1]
Measure=CPU
UpdateDivider=#BarWidth# + #Gap#
Processor=1

[mCPU2]
Measure=CPU
UpdateDivider=#BarWidth# + #Gap#
Processor=2

[MeasurePhysMemTotal]
Measure=PhysicalMemory
Total=1
UpdateDivider=30

[MeasurePhysMemUsed]
Measure=PhysicalMemory
UpdateDivider=30

[MeasurePhysMemFree]
Measure=PhysicalMemory
InvertMeasure=1
UpdateDivider=30

[MeasureUsedRAMPercent]
Measure=Calc
Formula=(MeasurePhysMemUsed / MeasurePhysMemTotal) * 100
UpdateDivider=30

[MeasureFreeRAMPercent]
Measure=Calc
Formula=(MeasurePhysMemFree / MeasurePhysMemTotal) * 100
UpdateDivider=30

[MeasureBatteryPercent]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
UpdateDivider=30

[orangeBar]
SolidColor=#Orange#
X=#Gap#R
Y=0
W=#BarWidth#
H=#SkinHeight#
Group=bars

[grayBar]
SolidColor=#Gray#
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

[CPU1Label]
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
Prefix="1"

[CPU2Label]
Meter=STRING
X=155
Y=69
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="2"

[CPU1Measurement]
Meter=STRING
MeasureName=mHistogramCPU1
X=100
Y=69
FontColor=#Orange#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="%"

[CPU2Measurement]
Meter=STRING
MeasureName=mHistogramCPU2
X=200
Y=69
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="%"

[RAMMeasurement]
Meter=STRING
MeasureName=MeasureUsedRAMPercent
X=10
Y=15
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="RAM  "
Postfix="%"

[BatteryMeasurement]
Meter=STRING
MeasureName=MeasureBatteryPercent
X=290
Y=15
FontColor=#Gray#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Postfix="%  PWR"
