declare variable $inputDocument external;
doc($inputDocument)/addressbook/contact[xs:integer(@number) = 1]/
concat(name, '; ', email, '; ', phone)