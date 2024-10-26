# Write your MySQL query statement below
select tab2.product_name, tab1.year, tab1.price
from Sales as tab1
inner join Product as tab2
on tab1.product_id = tab2.product_id