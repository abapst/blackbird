function Initialize()
	-- Tables to hold the meter handles and the 'h' for each meter
	Meters = {}		
	Values = {}
	
	-- grabs the various appearance options
	gap = SELF:GetNumberOption('Gap',0)
	height = SELF:GetNumberOption('Height',10)
	direction = SELF:GetNumberOption('FlipX',0) == 1
	orient = SELF:GetNumberOption('FlipY',0) == 1
	aggregate = SELF:GetNumberOption('Aggregate',1)
	xStrt = SELF:GetOption('Xstart')
	yStrt = SELF:GetOption('Ystart')
    meterWidth = SELF:GetNumberOption('Width',10) 
    barWidth = SELF:GetNumberOption('BarWidth',1)

	meterName = SELF:GetName()
	
	-- Gets the width of the histogram and divides that by the size of one bar 
	-- (including a gap) to get the number of bars in the histogram
	numBars = math.floor(meterWidth / (gap + barWidth)) + 1
	leftover = meterWidth - (numBars - 1) * (gap + barWidth)
	if leftover > 0 then
		numBars = numBars + 1
	end
	print('Leftover amount: ' .. leftover)
	
	measure = SKIN:GetMeasure(SELF:GetOption('Msr'))

	-- Create temp meter file if it doesn't exist
    currentPath = SELF:GetOption('CurrentPath')
	tempFile = currentPath .. 'temp.inc'
	local f = io.open(tempFile, 'w')
	f:close()

	-- Counter for time steps
	cnt = 0

	for i=1,numBars do
		SKIN:Bang('!WriteKeyValue',meterName .. '_' .. i,'Meter','IMAGE',tempFile)
		SKIN:Bang('!WriteKeyValue',meterName .. '_' .. i,'MeterStyle','sBar',tempFile)
		Meters[i] = SKIN:GetMeter(meterName .. '_' .. i)
		Values[i] = 0
	end
end

function Update()
	currentValue = measure:GetRelativeValue()

	if (cnt == 0) then
		if direction then
		-- if the chart should move from left to right...
			table.remove(Values)
			table.insert(Values, 1, currentValue)
		else
		-- if the chart should move from right to left...
			table.remove(Values, 1)
			table.insert(Values, currentValue)
		end
	end

	-- find the largest value in the Values table, to use for autoscaling later
	maxV = 0
	for i,v in ipairs(Values) do
		maxV = math.max(maxV,v)
	end
	
	-- iterates through the meters and sets their 'H' values from the Values table
	for i=1, numBars do
		h = math.ceil(Values[i]*height)
		-- used b/c Meter:SetH() would not work
		SKIN:Bang('!SetOption ' .. Meters[i]:GetName() .. ' H ' .. h)

		-- note: Lua (X and Y or Z) same as C++/Java (X ? Y : Z)
		Meters[i]:SetY(orient and yStrt or (height - h + yStrt))

		if (i == 1) then
			if direction then
				currentBarWidth = math.min(cnt + 1, barWidth)
			else
				currentBarWidth = barWidth - math.min(cnt + 1, barWidth)
			end
		elseif (i == numBars) then
			if direction then
				if leftover > 0 and leftover < barWidth then
					tempBarWidth = math.min(barWidth, leftover)
					currentBarWidth = tempBarWidth - math.min(cnt + 1, tempBarWidth)
				elseif leftover > 0 and leftover >= barWidth then
					grace = leftover - barWidth
					currentBarWidth = barWidth - math.min(math.max(0, cnt + 1 - grace), barWidth)
				else
					currentBarWidth = barWidth - math.min(cnt + 1, barWidth)
				end
			else
				currentBarWidth = math.min(cnt + 1, barWidth)
			end
		else
			currentBarWidth = barWidth
		end

		SKIN:Bang('!SetOption ' .. Meters[i]:GetName() .. ' W ' .. currentBarWidth)

		x = Meters[i]:GetX()
		if direction then
			if ((cnt + 1) > barWidth and i == 1 and currentBarWidth == barWidth) then
				Meters[i]:SetX(x + 1)
			elseif (i == 1 and currentBarWidth == 1) then
				Meters[i]:SetX(xStrt)
			end
		else
			if ((cnt + 1) > barWidth and i == 1 and currentBarWidth == 0) then
				Meters[i]:SetX(x - 1)
			elseif (i == numBars and currentBarWidth == 1) then
				Meters[1]:SetX(xStrt)
			end
		end

	end

	-- Update counter
	cnt = (cnt + 1) % (barWidth + gap)

	return math.floor(Values[1]*100)	-- could use this value in skin (not currently implemented)
end