/*SELECT S1.Score, (
    SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= S1.Score) AS `Rank`
FROM Scores S1
ORDER BY S1.Score DESC*/

SELECT Score,  (SELECT COUNT(DISTINCT(Score)) FROM  Scores b WHERE b.Score > a.Score) + 1 AS `Rank`
       FROM Scores a
       ORDER by Score DESC