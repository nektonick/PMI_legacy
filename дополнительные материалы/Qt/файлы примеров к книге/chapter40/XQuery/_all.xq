declare variable $inputDocument external;
doc($inputDocument)/addressbook/contact/
concat('(name:', name, ' email:', email, ' phone:', phone, ') ')