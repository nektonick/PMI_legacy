declare variable $inputDocument external;
for $x in doc($inputDocument)/addressbook/contact/name
where data($x) = "Kermit" 
order by $x
return data($x)
