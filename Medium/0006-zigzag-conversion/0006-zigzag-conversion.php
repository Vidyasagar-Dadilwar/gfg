class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        // For each letter we must:
        //  1. Determine the sense (-1: down; 1: up)
        //  2. Determine the row, based on the sense
        // Let's use two variables for that.
        $sense = 1;
        $row = 0;

        // Then, iterate over each letter and store them in different strings, to finally merge them.
        $rows = array_fill(0, $numRows, '');
        $s = str_split($s);
        foreach ($s as $char) {
            // Add char to correct substring
            $rows[$row] .= $char;

            // Update sense and row
            if (($row === 0 && $sense === -1)               // Up and reached first row
                || ($row === $numRows-1 && $sense === 1)    // Down and reached last row
            ) {
                $sense = -$sense;
            }
            $row += $sense;
        }
        return implode($rows);
    }
}