# Write your MySQL query statement below
select Product.product_name,year,price from sales left join product on sales.product_id=product.product_id order by sales.year DESC;