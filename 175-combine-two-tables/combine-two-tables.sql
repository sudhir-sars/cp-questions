-- Write your PostgreSQL query statement below
select c.firstName, c.lastName,a.city,a.state from Person as c 
left join Address as a on  c.personId=a.personId;