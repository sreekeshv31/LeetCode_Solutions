# Write your MySQL query statement below

select (select max(salary) from employee where salary not in(select max(salary) from employee)) SecondHighestSalary;