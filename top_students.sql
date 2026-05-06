-- Displays top 3 students in descending order --
SELECT ID, NAME FROM STUDENT
ORDER BY SCORE DESC, ID ASC
LIMIT 3;
