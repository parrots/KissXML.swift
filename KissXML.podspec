Pod::Spec.new do |spec|
    spec.name = "KissXML"
    spec.version = "5.0"
    spec.summary = "A replacement for Cocoa's NSXML cluster of classes. Based on libxml."

    spec.homepage = "https://github.com/parrots/KissXML.swift"
    spec.license = {
        :type => 'MIT',
        :file => 'LICENSE'
    }
    spec.author = {
        "Robbie Hanson" => "robbiehanson@deusty.com",
        "Curtis Herbert" => "me@curtisherbert.com"
    }
    spec.source = {
        :git => 'https://github.com/parrots/KissXML.swift.git'
    }
    spec.source_files = 'KissXML/**/*.{h,m}'
    spec.public_header_files = 'KissXML/**/*.h'
    spec.library      = 'xml2'
    spec.requires_arc = true
    spec.xcconfig     = { 
        'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libxml2', 
        'OTHER_LDFLAGS' => '-ObjC -lxml2' 
    }
end