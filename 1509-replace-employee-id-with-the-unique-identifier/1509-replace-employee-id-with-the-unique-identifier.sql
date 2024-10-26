select tab2.unique_id , tab1.name
from Employees as tab1
left join EmployeeUNI as tab2
on tab1.id = tab2.id