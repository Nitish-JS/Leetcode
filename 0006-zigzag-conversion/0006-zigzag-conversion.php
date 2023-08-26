<?php

    class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
    if ($numRows == 1 || $numRows >= strlen($s)) {
        return $s;
    }

    $rows = array_fill(0, $numRows, '');
    $idx = 0;
    $step = 1;

    for ($i = 0; $i < strlen($s); $i++) {
        $rows[$idx] .= $s[$i];
        if ($idx == 0) {
            $step = 1;
        } else if ($idx == $numRows - 1) {
            $step = -1;
        }
        $idx += $step;
    }

    return implode('', $rows);
}

}

?>