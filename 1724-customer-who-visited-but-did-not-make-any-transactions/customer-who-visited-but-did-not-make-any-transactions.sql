# Write your MySQL query statement below
select visits.customer_id,count(visits.customer_id) as count_no_trans from visits left join Transactions on Visits.visit_id=Transactions.visit_id where Transactions.transaction_id is null group by visits.customer_id
