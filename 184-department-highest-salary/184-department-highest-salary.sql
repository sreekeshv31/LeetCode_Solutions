# Write your MySQL query statement below

select d.name as Department,e.name as Employee ,e.salary as Salary from Department d JOIN Employee e ON e.departmentId = d.id
where e.salary in (select max(e1.salary) from Employee e1 where e1.departmentId = e.departmentId)