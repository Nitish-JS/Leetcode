function convert(s, numRows) {
    if (numRows === 1 || numRows >= s.length) {
        return s;
    }

    let rows = Array.from({ length: numRows }, () => '');
    let idx = 0, step = 1;

    for (let c of s) {
        rows[idx] += c;
        if (idx === 0) {
            step = 1;
        } else if (idx === numRows - 1) {
            step = -1;
        }
        idx += step;
    }

    return rows.join('');
}