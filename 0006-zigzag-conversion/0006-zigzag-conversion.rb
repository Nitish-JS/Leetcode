def convert(s, numRows)
    return s if numRows == 1 || numRows >= s.length
    rows = Array.new(numRows) { "" }
    idx, step = 0, 1
    s.each_char do |c|
        rows[idx] += c
        if idx == 0
            step = 1
        elsif idx == numRows - 1
            step = -1
        end
        idx += step
    end
    rows.join("")
end