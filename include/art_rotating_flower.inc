[Variables]
img=#@#images\blue_sarinth.png
logocolor=255,255,255,255

[Background]
Meter=IMAGE
SolidColor=0, 0, 0, 1
W=121
H=121

[Measuretime]
Measure=Calc
Formula=Counter %150

[MeterSpinningFlower]
Meter=Rotator
MeasureName=MeasureTime
X=0
Y=0
W=121
H=121
Greyscale=1
ImageTint=#logocolor#
ImageName=#img#
ValueRemainder=150
OffsetX=61
OffsetY=61
StartAngle=6.2832
RotationAngle=6.2832