[Variables]
MeterHeight=30
MeterWidth=280
SkinHeight=140
SkinWidth=300
Gap=1
BarWidth=2
White=255,255,255,255
CPU_X=0
CPU_Y=0

[CPUBackground]
Meter=IMAGE
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=#SkinWidth#
H=#SkinHeight#
X=#CPU_X#
Y=#CPU_Y#

;These includes must happen after the background meter is drawn so they are drawn on top
@Include1=#CurrentPath#temp\temp_mHistogramCPU1.inc
@Include2=#CurrentPath#temp\temp_mHistogramCPU2.inc

[CPUBottomLine]
Meter=IMAGE
X=(10+#CPU_X#)
Y=(130+#CPU_Y#)
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
Xstart=(10+#CPU_X#)
Ystart=(40+#CPU_Y#)

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
Xstart=(10+#CPU_X#)
Ystart=(90+#CPU_Y#)

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
SolidColor=#AccentColor1#
X=#Gap#R
Y=0
W=#BarWidth#
H=#SkinHeight#
Group=bars

[grayBar]
SolidColor=#AccentColor2#
X=#Gap#R
Y=0
W=#BarWidth#
H=#SkinHeight#
Group=bars

[InnerLine1]
Meter=IMAGE
X=(10+#CPU_X#)
Y=(70+#CPU_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[InnerLine2]
Meter=IMAGE
X=(10+#CPU_X#)
Y=(90+#CPU_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[MiddleDivider]
Meter=IMAGE
X=(150+#CPU_X#)
Y=(70+#CPU_Y#)
W=1
H=20
SolidColor=255, 255, 255, 50

[CPU1Label]
Meter=STRING
X=(145+#CPU_X#)
Y=(69+#CPU_Y#)
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Prefix="1"

[CPU2Label]
Meter=STRING
X=(155+#CPU_X#)
Y=(69+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Prefix="2"

[CPU1Measurement]
Meter=STRING
MeasureName=mHistogramCPU1
X=(100+#CPU_X#)
Y=(69+#CPU_Y#)
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="%"

[CPU2Measurement]
Meter=STRING
MeasureName=mHistogramCPU2
X=(200+#CPU_X#)
Y=(69+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="%"

[RAMMeasurement]
Meter=STRING
MeasureName=MeasureUsedRAMPercent
X=(10+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Prefix="RAM  "
Postfix="%"

[BatteryMeasurement]
Meter=STRING
MeasureName=MeasureBatteryPercent
X=(290+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=12
StringAlign=RIGHT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="%  PWR"
