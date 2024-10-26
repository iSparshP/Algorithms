# Write your MySQL query statement below
select customer_id , count(customer_id) as count_no_trans
from Visits as table1
left join Transactions as table2
on table1.visit_id = table2.visit_id
where transaction_id is null
group by customer_id