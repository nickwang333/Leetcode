# Write your MySQL query statement below
SELECT abs(
(SELECT
    max(salary)
FROM
    Salaries
WHERE
    department = 'Engineering')
-
(SELECT
    max(salary)
FROM
    Salaries
WHERE
    department = 'Marketing')
) as salary_difference
