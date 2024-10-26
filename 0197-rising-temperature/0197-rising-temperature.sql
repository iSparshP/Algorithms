# Write your MySQL query statement below
select table1.id
from Weather as table1
left join Weather as table2
on table1.recordDate = DATE_ADD(table2.recordDate, INTERVAL 1 DAY)
where table1.temperature > table2.temperature